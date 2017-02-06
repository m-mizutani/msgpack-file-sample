const fs = require('fs');
const msgpack = require('msgpack-lite');

var rs = fs.createReadStream('data.msg');
var ds = msgpack.createDecodeStream();

rs.pipe(ds).on('data', (msg) => {
  console.log(msg);
});
