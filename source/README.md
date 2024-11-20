Pr. Rogers is kind of superstitious person. First he insisted that no one used the number 13 around him. Then he extends it to the number 7.
Nowadays he won't work with anything that is a prime number.

Can you make that program work? He build a special interpreter that won't allow any prime in the opcodes (either as hex (x13) or in dec (13 --> 0xd))





# Unicorn
`pip install unicorn`

# QEMU
```
sudo apt-get install git libglib2.0-dev libfdt-dev libpixman-1-dev zlib1g-dev ninja-build
sudo apt-get install python3-venv
sudo apt install python3-capstone
cd qemu
./configure --target-list=x86_64-linux-user
make -j$(nproc)
```
