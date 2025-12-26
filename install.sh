if [[ -z $1 ]]; then
  privesc=sudo
  echo This installation script assumes that you use sudo as your privilege escalation tool. If you do not, please pass your privilege escalation tool as the first argument to install.sh. For example: \`install.sh pkexec\`
  printf " - \e[1;31mScript will stop for 5 seconds.\e[0m\n"
  sleep 5
  echo Continuing.
else
  echo Using $1 as privilege escalation tool.
  privesc=$1
fi

spwd=$(pwd) # get the pwd so it can be returned to later

printf "\e[1;37m===>\e[0m Welcome to EBSL!\n"
printf "\e[1;37m==>\e[0m CMake (1) or Meson (2)? (default=1): "
read buildchoice

if [[ -z $buildchoice ]] || [[ $buildchoice -eq 1 ]]; then
  printf "\e[1;34m==>\e[0m Building with CMake\n"
  cmake -Bbuild
  cd build && make
  echo cmake
elif [[ $buildchoice -eq 2 ]]; then
  printf "\e[1;34m==>\e[0m Building with Meson\n"
  meson build
  cd build && ninja
  echo meson
else
  printf "  \e[0;31mx\e[0m Invalid option. Nothing done.\n"
  exit 1
fi

echo in $(pwd)
cd $spwd
echo in $(pwd)

printf "\e[1;37m==>\e[0m Installing ebsl...\n"

$privesc install -Dm755 build/ebsl /usr/bin/ebsl

printf "\e[1;37m==>\e[0m Installing manpage...\n"

gzip man1/ebsl.1

$privesc install -Dm644 man1/ebsl.1.gz /usr/share/man/man1/ebsl.1.gz

echo Done!
