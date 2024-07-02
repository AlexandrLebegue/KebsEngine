# set-executionpolicy remotesigned #un-comment this line if powerhell script are disabled
$SDL_VERSION = "2.30.4" #Latest version of sdl
$SDL_VERSION_IMAGE = "2.8.2"
mkdir sdl_installation
cd sdl_installation
echo "Getting SDL $SDL_VERSION "
wget https://github.com/libsdl-org/SDL/releases/latest/download/SDL2-devel-$SDL_VERSION-VC.zip -o sdl.zip
echo "Getting SDL Image $SDL_VERSION_IMAGE"
wget https://github.com/libsdl-org/SDL_image/releases/latest/download/SDL2_image-devel-$SDL_VERSION_IMAGE-VC.zip  -o sdl_image.zip
echo "Done !" 
echo "Unziping SDL .." 
Expand-Archive sdl.zip windows_install/ 
Expand-Archive sdl_image.zip windows_install/ 

echo "Done !"
echo "Removing temp file"
Remove-Item sdl.zip
Remove-Item sdl_image.zip
echo "Done !" 
echo "Then, you can specify the correct path in the cmake preset" 
cd ..

# then specify the correct path in the cmake preset 
