# Download libraries Manually (Ubuntu 22.04.2 LTS)

## Download dependencies
### Go to these links
- https://github.com/raysan5/raylib

### Download the released source files
- raylib-X.X.X_linux_arch - [raylib]

### Install Raylib
```
cd raylib-X.X.X_OS_arch
sudo cp lib/* /usr/local/lib/
sudo cp include/* /usr/local/include/
```

## Configure Linker
### Setup links and cache after installing libraries manually
```
sudo ldconfig
```
