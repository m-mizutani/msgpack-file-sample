# -*- coding: utf-8 -*-

require "msgpack"

File.open("data.msg") do |file|
  MessagePack::Unpacker.new(file).each do |obj|
    puts obj
  end
end

