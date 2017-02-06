# -*- coding: utf-8 -*-

require "msgpack"

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

File.open("data.msg", "w") do |file|
  file.write(obj1.to_msgpack)
  file.write(obj2.to_msgpack)
end

