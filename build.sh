clear

if [ ! -d "/bin" ]
then
    echo "Creating DIR bin"
    mkdir ./bin
fi

if [ -e ./bin/Pong ]
then
    rm -rf ./bin/Pong
fi

gcc -fdiagnostics-color=always -g Main.c -o ./bin/Pong -lSDL2 -I/usr/include/SDL2 -lSDL2_ttf -I/home/jamie/projects/Pong/ -D_REENTRANT 

if [ -e ./bin/Pong ]
then
    ./bin/Pong
fi