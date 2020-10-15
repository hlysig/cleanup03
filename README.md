
## setup
sudo curl -L "https://github.com/docker/compose/releases/download/1.26.0/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose



## Build

```
mkdir build; cd $_
cmake ../
make
```



## Setup on mac

```
brew install cmake
brew install xmlto
git clone https://github.com/jtv/libpqxx.git
cd libpqxx
./configure
make
make install
brew install boost-python3
```
