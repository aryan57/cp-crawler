const got = require('got')
const axios = require('axios')
const cheerio = require("cheerio")

const Problem = require('./problem.js')
const options = require('../options.json')
const crawler = require('./crawler.js')
const saveFile = require('./saveProblem')

const getCodeforcesSubmissions = async () => {
    if (!options.codeforcesHandle || typeof (options.codeforcesHandle) !== "string" || options.codeforcesHandle.length == 0) return
    try {
        var submissions = await axios.get(`https://codeforces.com/api/user.status?handle=${options.codeforcesHandle}`); // '&from=1&count=10'
        submissions = submissions.data.result
        for (var i = 0; i < submissions.length; i++) {

            var problem = new Problem()
            problem.isAC = submissions[i].verdict === 'OK' ? true : false
            if (problem.isAC === false && options.onlyAC === true) continue

            problem.fileExtension = options.defaultExtension
            if (submissions[i].programmingLanguage in options.extensionMapping
                && options.extensionMapping[submissions[i].programmingLanguage].length > 0) {
                problem.fileExtension = options.extensionMapping[submissions[i].programmingLanguage]
            }

            problem.name = submissions[i].problem.index + ' - ' + submissions[i].problem.name
            problem.groupName = submissions[i].contestId
            problem.url = `https://codeforces.com/contest/${submissions[i].contestId}/submission/${submissions[i].id}`

            await crawler.scrapeCodeforces(problem)

            problem.fileName = problem.name + (options.giveUniqueNames ? "-" + submissions[i].id : "") + problem.fileExtension
            problem.filePath = `./${options.codeforcesHandle}/${problem.groupName}`
            saveFile.saveProblem(problem)
        }

    } catch (error) {
        console.error(error.message)
    }
};

const getAtcoderSubmissions = async () => {
    if (!options.atcoderHandle || typeof (options.atcoderHandle) !== "string" || options.atcoderHandle.length == 0) return
    try {

        var startDate = new Date()
        // kenkoooo api will give maximum 500 submissions, so dont go too much before in time
        startDate.setDate(startDate.getDate() - options.atcoderMaxPrevDays)
        startDate = Math.floor(startDate.getTime() / 1000)

        var submissions = await got.get(`https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user=${options.atcoderHandle}&from_second=${startDate}`);
        submissions = submissions.body;
        submissions = JSON.parse(submissions)

        for (var i = 0; i < submissions.length; i++) {
            var problem = new Problem()
            problem.isAC = submissions[i].result === 'AC' ? true : false
            if (problem.isAC === false && options.onlyAC === true) continue

            problem.fileExtension = options.defaultExtension
            if (submissions[i].language in options.extensionMapping && options.extensionMapping[submissions[i].language].length > 0) {
                problem.fileExtension = options.extensionMapping[submissions[i].language]
            }
            problem.groupName = submissions[i].contest_id
            problem.url = `https://atcoder.jp/contests/${submissions[i].contest_id}/submissions/${submissions[i].id}`
            await crawler.scrapeAtcoder(problem)
            problem.fileName = problem.name + (options.giveUniqueNames ? "-" + submissions[i].id : "") + problem.fileExtension
            problem.filePath = `./${options.atcoderHandle}/${problem.groupName}`
            saveFile.saveProblem(problem)
        }

    } catch (error) {
        console.error(error.message)
    }
};

const getCodechefSubmissions = async () => {
    if (!options.codechefHandle || typeof (options.codechefHandle) !== "string" || options.codechefHandle.length == 0) return
    try {
        const solutionPage = await axios.get(`https://www.codechef.com/users/${options.codechefHandle}`);
        var $ = cheerio.load(solutionPage.data);

        var submissions = []

        $('h5').each(function (i, e) {

            if ($(this).text().startsWith('Fully Solved')) {

                $(e).next().find('a').each(function () {
                    submissions.push("https://www.codechef.com" + $(this).attr('href'));
                })

                return false // this will break the .each loop
            }
        })

        var result = []

        for (let index = 0; index < submissions.length; index++) {
            let url = submissions[index]
            const statusPage = await axios.get(url)
            $ = cheerio.load(statusPage.data)

            let arr = url.split('/')
            let isPractice = false
            for (let i = 1; i < arr.length; i++) {
                if (arr[i] === 'status' && arr[i - 1].endsWith('codechef.com')) {
                    isPractice = true
                    break
                }
            }

            const contestName = isPractice ? "Practice" : $("#breadcrumb > div :nth-child(3)").text()
            const problemName = isPractice ? $("#breadcrumb > div :nth-child(3)").text() : $("#breadcrumb > div :nth-child(4)").text()

            $("div.tablebox-section.l-float").find('a').each(async function () {
                const link = $(this).attr('href')
                if (link.startsWith("/viewsolution/")) {
                    var problem = new Problem()
                    problem.url = "https://www.codechef.com" + link
                    problem.name = problemName
                    problem.groupName = 'Codechef - ' + contestName
                    await crawler.scrapeCodechef(problem)
                    if (problem.isAC === true || options.onlyAC === false) {
                        let id = problem.url.split('/').pop()
                        problem.fileName = problem.name + (options.giveUniqueNames ? "-" + id : "") + problem.fileExtension
                        problem.filePath = `./${options.codechefHandle}/${problem.groupName}`
                        saveFile.saveProblem(problem)
                    }


                }
            })
        }

    } catch (error) {
        console.error(error.message)
    }
};

module.exports = {
    getCodeforcesSubmissions,
    getAtcoderSubmissions,
    getCodechefSubmissions
}
