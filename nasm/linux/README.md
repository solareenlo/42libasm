# nasm/linux

## Usage
```shell
docker pull solareenlo/42docker
docker run -it --rm -v $(pwd):/libasm solareenlo/42docker
cd libasm
asm hello
./hello
rmasm hello
```
