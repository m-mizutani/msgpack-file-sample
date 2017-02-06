#include <msgpack.hpp>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  static const size_t BUFSIZE = 4; // あえてバッファサイズ小さめに
  int rc;
  char buf[BUFSIZE];

  int fd = open("data.msg", O_RDONLY);
  
  msgpack::unpacker unpkr;
  while (0 < (rc = read(fd, buf, sizeof(buf)))) {
    unpkr.reserve_buffer(rc);
    memcpy(unpkr.buffer(), buf, rc);
    unpkr.buffer_consumed(rc);

    msgpack::object_handle result;
    while (unpkr.next(result)) {
      const msgpack::object &obj = result.get();

      if (obj.type == msgpack::type::MAP) {
        printf("{\n");
        msgpack::object_kv* p(obj.via.map.ptr);

        for(msgpack::object_kv* const pend(obj.via.map.ptr + obj.via.map.size);
            p < pend; ++p) {
          
          std::string key;
          p->key.convert(key);

          if (key == "name") {
            std::string value;
            p->val.convert(value);
            printf("  %s: %s,\n", key.c_str(), value.c_str());
          }

          if (key == "age") {
            int value;
            p->val.convert(value);
            printf("  %s: %d,\n", key.c_str(), value);
          }

          if (key == "hist") {
            msgpack::object arr = p->val;
            printf ("  %s, [", key.c_str());
            for (int i = 0; i < arr.via.array.size; i++) {
              int value;
              arr.via.array.ptr[i].convert(value);

              printf("%d, ", value);
            }
            printf ("],\n");
          }          
        }

        printf("}\n");
      }
      
      result.zone().reset();
    }
  }

  return 0;
}

