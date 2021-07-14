const axios = require('axios')
const cheerio = require("cheerio");
const Problem = require('./problem.js')

const scrapeCodeforces = async (problem) => {
    try {
        // scrap problem source code
        const solutionPage = await axios.get(problem.url);
        var $ = cheerio.load(solutionPage.data);
        problem.sourceText = $("#program-source-text").text();
        
        // scrap problem contest name
        const contestPage = await axios.get("https://codeforces.com/contest/1547");
        $ = cheerio.load(contestPage.data);
        var contestName = $("head > title").text();
        contestName = contestName.split('-')[1].trim()
        problem.groupName = 'Codeforces - ' + contestName

    } catch (error) {
        console.error(error.message)
    }
};

const scrapeAtcoder = async (problem) => {
    try {
        const solutionPage = await axios.get(problem.url);
        const $ = cheerio.load(solutionPage.data);

        problem.sourceText = $("#submission-code").text();

    } catch (error) {
        console.error(error.message)
    }
};
const scrapeCodechef = async (problem) => {
    try {
        const solutionPage = await axios.get(problem.url);
        const searchString = "var meta_info = "
        // cheerio wasn't working for grabbing variables from script tag here, so did string manipulation
        const html = solutionPage.data.split(/\n/);

        for (var i = 0; i < html.length; i++) {
            const text = html[i]
            for (var j = 0; j < Math.min(text.length, 5); j++) {
                if (text.substring(j, j + searchString.length) === searchString) {
                    const metaDataText = text.substring(j + searchString.length).slice(0, -1)
                    const obj = JSON.parse(metaDataText)
                    problem.sourceText = obj['data']['plaintext']
                }
            }
        }

    } catch (error) {
        console.error(error.message)
    }
};

module.exports = {
    scrapeAtcoder,
    scrapeCodechef,
    scrapeCodeforces
}