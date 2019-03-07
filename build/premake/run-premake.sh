#
# remove any generated build files
#
rm -rf ..\gmake
rm -rf ..\vs2017
rm -rf ..\obj
#
# create new build files files
#
./premake5-alpha13 --os=linux --file=premake5.lua gmake
