# coding: UTF-8

import msgpack

for msg in msgpack.Unpacker(open('data.msg', 'rb')):
    print msg
