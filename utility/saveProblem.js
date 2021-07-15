const fs = require('fs')
const options = require('../options.json')


const saveProblem = async (problem) => {


    try {
        await fs.promises.mkdir(problem.filePath, { recursive: true });
    } catch (error) {
        console.error(err);
    }

    problem.filePath = problem.filePath + '/' + problem.fileName

    try {
        await fs.promises.access(problem.filePath);
        //  file already exists
        if (options.overwrite) {
            fs.writeFile(problem.filePath, problem.sourceText, function (err) {
                if (err) {
                    return console.error(err);
                }
                console.log(`Successfully scraped ${problem.fileName} : ${problem.groupName}`);
            });
        } else {
            console.log(`${problem.fileName} : ${problem.groupName} already exists.`);
        }
    } catch (error) {
        //  file doesnt exists
        fs.writeFile(problem.filePath, problem.sourceText, function (err) {
            if (err) {
                return console.error(err);
            }
            console.log(`Successfully scraped ${problem.fileName} : ${problem.groupName}`);
        });
    }
}

module.exports = {
    saveProblem
}