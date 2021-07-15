const fs = require('fs')
const options = require('../options.json')


const saveProblem = async (problem) => {


    await fs.mkdir(problem.filePath, { recursive: true }, (err) => {
        if (err) throw err;
    });

    problem.filePath = problem.filePath + '/' + problem.fileName

    try {
        await fs.promises.access(problem.filePath);
        //  file already exists
        if (options.overwrite) {
            fs.writeFile(problem.filePath, problem.sourceText, function (err) {
                if (err) {
                    return console.log(err);
                }
                console.log(`Successfully scraped ${problem.fileName} : ${problem.groupName}`);
            });
        }
    } catch (error) {
        //  file doesnt exists
        fs.writeFile(problem.filePath, problem.sourceText, function (err) {
            if (err) {
                return console.log(err);
            }
            console.log(`Successfully scraped ${problem.fileName} : ${problem.groupName}`);
        });
    }
}

module.exports = {
    saveProblem
}