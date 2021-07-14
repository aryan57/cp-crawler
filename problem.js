class Problem {
    constructor(fileName, groupName, url, isAC, sourceText) {
        this.groupName = groupName
        this.isAC = isAC
        this.url = url
        this.fileName = fileName
        this.sourceText = sourceText
    }
}

module.exports = Problem;