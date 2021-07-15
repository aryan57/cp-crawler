class Problem {
    constructor(fileName, groupName, url, isAC, sourceText,fileExtension, name,filePath) {
        this.groupName = groupName
        this.isAC = isAC
        this.url = url
        this.fileName = fileName
        this.sourceText = sourceText
        this.fileExtension = fileExtension
        this.name = name
        this.filePath = filePath
    }
}

module.exports = Problem;