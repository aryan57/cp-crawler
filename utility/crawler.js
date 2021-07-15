const axios = require('axios')
const cheerio = require("cheerio");
const options = require('../options.json')

const scrapeCodeforces = async (problem) => {
    try {
        // scrap problem source code
        const solutionPage = await axios.get(problem.url);
        var $ = cheerio.load(solutionPage.data);
        problem.sourceText = $("#program-source-text").text();

        let contestHomePage = ""
        let arr = problem.url.split('/')
        for(let i=1;i<arr.length-1;i++) {
            if(arr[i-1]==='contest' && arr[i+1]=='submission') {
                contestHomePage = "https://codeforces.com/contest/" + arr[i]
                break
            }
        }

        // scrap problem contest name
        const contestPage = await axios.get(contestHomePage);
        $ = cheerio.load(contestPage.data);
        var contestName = $("head > title").text();

        // s1 - contestname(which can contain '-') - s2
        contestName = contestName.split('-')
        contestName.shift()
        contestName.pop()
        contestName = contestName.join('-')
        contestName = contestName.trim()
        problem.groupName = 'Codeforces - ' + contestName

    } catch (error) {
        console.error(`[error in scraping ${problem.url} from codeforces]\t` + error.message)
    }
};

const scrapeAtcoder = async (problem) => {
    try {
        const solutionPage = await axios.get(problem.url);
        const $ = cheerio.load(solutionPage.data);

        problem.sourceText = $("#submission-code").text();
        var contestName = $("head > title").text();

        // s1 - contestname(which can contain '-')
        contestName = contestName.split('-')
        contestName.shift()
        contestName = contestName.join('-')
        contestName = contestName.trim()
        problem.groupName = 'Atcoder - ' + contestName

        $('th').each(function (i, ele) {

            if ($(this).text() === 'Task') {
                problem.name = $(this).next().text()
                return false // this will break the .each loop
            }
        })

    } catch (error) {
        console.error(`[error in scraping ${problem.url} from atcoder]\t` + error.message)
    }
};
const scrapeCodechef = async (problem) => {
    try {
        const solutionPage = await axios.get(problem.url);
        const searchString = "var meta_info = "
        const $ = cheerio.load(solutionPage.data);

        // cheerio wasn't working for grabbing variables from script tag here, so did string manipulation
        const html = solutionPage.data.split(/\n/);

        for (var i = 0; i < html.length; i++) {
            const text = html[i]
            for (var j = 0; j < Math.min(text.length, 5); j++) {
                if (text.substring(j, j + searchString.length) === searchString) {
                    const metaDataText = text.substring(j + searchString.length).slice(0, -1)
                    const obj = JSON.parse(metaDataText)
                    problem.sourceText = obj['data']['plaintext']
                    problem.fileExtension = options.defaultExtension
                    problem.isAC = false
                    if (obj['data']['languageExtension'] && obj['data']['languageExtension'].length > 0) {
                        problem.fileExtension = '.'+obj['data']['languageExtension']
                    }
                    if (obj['data']['solutionResult'] && obj['data']['solutionResult']==='AC') {
                        problem.isAC = true
                    }
                }
            }
        }

    } catch (error) {
        console.error(`[error in scraping ${problem.url} from codechef]\t` + error.message)
    }
};

module.exports = {
    scrapeAtcoder,
    scrapeCodechef,
    scrapeCodeforces
}