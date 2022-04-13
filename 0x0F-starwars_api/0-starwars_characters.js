#!/usr/bin/node

const request = require('request');

async function starwars (id) {
  const url = `https://swapi-api.hbtn.io/api/films/${id}`;

  request(url, async function (err, response, body) {
    if (err) return console.log(err);
    const charList = JSON.parse(body).characters;

    for (const chatUrl of charList) {
        const ret = () => {
            return new Promise((resolve, reject) => {
                request(chatUrl, function (err, response, body) {
                if (err) {
                    console.log(err);
                } else {
                    resolve(JSON.parse(body).name);
                }
            });
          });
        };
        console.log(await ret());
      }
  });
}

if (process.argv.length === 3) {
    starwars(process.argv[2]);
}
