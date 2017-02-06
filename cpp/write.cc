#include <msgpack.hpp>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open("data.msg", O_WRONLY | O_CREAT, 0600);
  
  msgpack::sbuffer buf1, buf2;;
  msgpack::packer<msgpack::sbuffer> pk1(&buf1), pk2(&buf2);

  pk1.pack_map(3);
  pk1.pack("name"); pk1.pack("Alice");
  pk1.pack("age");  pk1.pack(27);
  pk1.pack("hist");
  pk1.pack_array(3);
  pk1.pack(5); pk1.pack(3); pk1.pack(1);

  write(fd, buf1.data(), buf1.size());


  pk2.pack_map(3);
  pk2.pack("name"); pk2.pack("Bob");
  pk2.pack("age");  pk2.pack(33);
  pk2.pack("hist");
  pk2.pack_array(2);
  pk2.pack(4); pk2.pack(5);

  write(fd, buf2.data(), buf2.size());
  
  close(fd);
}
