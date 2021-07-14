const Problem = require('./problem.js')
const options = require('./options.json')
const axios = require('axios')

const getCodeforcesSubmissions = async () => {
    if (!options.codeforcesHandle || typeof (options.codeforcesHandle) !== "string" || options.codeforcesHandle.length == 0) return []
    try {
        var submissions = await axios.get(`https://codeforces.com/api/user.status?handle=${options.codeforcesHandle}` + '&from=1&count=10');
        submissions = submissions.data.result
        var result = []
        // console.log(submissions[0]);
        for (var i = 0; i < submissions.length; i++) {
            var problem = new Problem()
            var fileExtension = options.defaultExtension
            if (submissions[i].programmingLanguage in options.extensionMapping && options.extensionMapping[submissions[i].programmingLanguage].length > 0) {
                fileExtension = options.extensionMapping[submissions[i].programmingLanguage]
            }
            problem.fileName = submissions[i].problem.index + '. ' + submissions[i].problem.name + fileExtension
            problem.groupName = submissions[i].contestId
            problem.isAC = submissions[i].verdict === 'OK' ? true : false
            problem.url = `https://codeforces.com/contest/${submissions[i].contestId}/submission/${submissions[i].id}`
            console.log(problem)
            result.push(problem)
        }
        return result

    } catch (error) {
        console.error(error.message)
    }

    return []
};

const getAtcoderSubmissions = async () => {
    if (!options.atcoderHandle || typeof (options.atcoderHandle) !== "string" || options.atcoderHandle.length == 0) return []
    try {

        var startDate = new Date()
        startDate.setDate(startDate.getDate() - options.atcoderMaxPrevDays) // kenkoooo api will give maximum 500 submissions, so dont go too much before in time
        startDate = Math.floor(startDate.getTime / 1000)
        startDate=1560046356
        console.log(`https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user=${options.atcoderHandle}&from_second=${startDate}`)
        var submissions = await axios.get("https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user=aryan57&from_second=1560046356");

        submissions = submissions.data.result
        var result = []
        console.log(submissions[0]);
        for (var i = 0; i < submissions.length; i++) {
            // var problem = new Problem()
            // var fileExtension = options.defaultExtension
            // if (submissions[i].programmingLanguage in options.extensionMapping && options.extensionMapping[submissions[i].programmingLanguage].length > 0) {
            //     fileExtension = options.extensionMapping[submissions[i].programmingLanguage]
            // }
            // problem.fileName = submissions[i].problem.index + '. ' + submissions[i].problem.name + fileExtension
            // problem.groupName = submissions[i].contestId
            // problem.isAC = submissions[i].verdict === 'OK' ? true : false
            // problem.url = `https://Atcoder.com/contest/${submissions[i].contestId}/submission/${submissions[i].id}`
            // console.log(problem)
            // result.push(problem)
        }
        return result

    } catch (error) {
        console.error(error.message)
    }

    return []
};

// getAtcoderSubmissions()


module.exports = {
    getCodeforcesSubmissions,
    getAtcoderSubmissions
}
