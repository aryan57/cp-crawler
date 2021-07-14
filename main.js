const crawler = require('./crawler.js')
const submissions = require('./submissions.js')

// crawler.scrapeCodechef(`https://www.codechef.com/viewsolution/48186261`).then(msg => console.log(msg));
// crawler.scrapeAtcoder(`https://atcoder.jp/contests/abc209/submissions/24118878`).then(msg => console.log(msg));
// crawler.scrapeCodeforces(`https://codeforces.com/contest/1547/submission/122206702`).then(msg => console.log(msg));


async function main() {
    var temp = await submissions.getCodeforcesSubmissions();

    for(var i=0;i<temp.length;i++) {
        await crawler.scrapeCodeforces(temp[i])
        console.log(temp[i])
    }

    
}

main()