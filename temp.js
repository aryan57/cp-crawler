const axios = require('axios')

async function  o6969 ()
{
    console.log('fwfw');
    // var submissions ="6969";
    try{
        var submissions = await axios.get("https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user=aryan57&from_second=1560046356");
        
    }catch (error) {
        console.error(error['response'])
    }

    console.log(submissions)

}

o6969()
