file "build/test.elf"

target extended-remote :3333

load
break main

continue
