#!/usr/bin/node

const request = require('request');

const id = process.argv[2] + '/';

const myUrl = 'https://swapi-api.hbtn.io/api/films/';

request(myUrl + id, async function (err, res, body) {
  if (err) return console.error(err);

  const urlList = JSON.parse(body).characters;

  for (const urlchar of urlList) {
    await new Promise(function (resolve, reject) {
      request(urlchar, function (err, res, body) {
        if (err) return console.error(err);
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
