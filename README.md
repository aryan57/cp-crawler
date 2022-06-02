Competitive Programming Crawler
==========
 `Competitive Programming Crawler` is a tool which will crawl all your codes from websites [codeforces](https://codeforces.com/), [codechef](https://www.codechef.com/) and [atcoder](https://atcoder.jp/) using web scraping and automatically downloads the solution codes.
 
 Installation
----------
``` bash
git clone https://github.com/aryan57/cp-crawler
```

**Dependency**
``` bash
npm install
```
How to use
----------
- First configure `options.json` file according to your needs
- Then run the tool as follows.
``` bash
node main.js
```
> - Search **all submitted** source code and analyze and download source code.

- **options.json**

| **option**            | **Description**
|:-------------------|:-------------------------------------------------------------------------------------------
| **codeforcesHandle**         | Your codeforces handle (username). Leave empty `""` if you dont want it.
| **codechefHandle**         | Your codechef handle (username). Leave empty `""` if you dont want it.
| **atcoderHandle**         | Your atcoder handle (username). Leave empty `""` if you dont want it.
| **onlyAC**          | `true` if you only want the accepted codes, else `false`. Beneficial to set it to `true`
| **overwrite**    | `true` if you want to overwrite codes when they are already present in the export directory, else `false`. It will be beneficial to set it to `false`,because if you run `node main.js` again, files will not be overwritten unnecessarily .
| **giveUniqueNames**          | `true` if you only want all the codes of the same problem, else `false`. When set to `true` different codes of the same problem will be differentiated using their unique Ids. It will be beneficial to set it to `false`,because generally we are concerned with any one code .




**_TODO_**

Implment better scraping method for codechef :-
 - use these apis https://www.codechef.com/viewplaintext/49358071
 - https://www.codechef.com/recent/user?user_handle=aryan57&page=20
