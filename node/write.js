const fs = require('fs');
const msgpack = require('msgpack-lite');

const obj1 = {
  name: "Alice", 
  age: 27,
  hist: [5, 3, 1]
};
const obj2 = {
  name: "Bob", 
  age: 33,
  hist: [4, 5]
};

fs.open('data.msg', 'w', (err, fd) => {
  fs.writeSync(fd, msgpack.encode(obj1));
  fs.writeSync(fd, msgpack.encode(obj2));
});
