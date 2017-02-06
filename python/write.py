# coding: UTF-8

import msgpack

obj1 = {
    "name": "Alice", 
    "age": 27,
    "hist": [5, 3, 1]
}
obj2 = {
    "name": "Bob", 
    "age": 33,
    "hist": [4, 5]
}

with open('data.msg', 'w') as fd:
    fd.write(msgpack.packb(obj1))
    fd.write(msgpack.packb(obj2))
