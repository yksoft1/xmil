DIR=("../.." "../../common")
DIR+=(
    "../../embed"
    "../../embed/menu"
    "../../embed/menubase"
    )
DIR+=("../../fdd")
DIR+=("../../font")
DIR+=("../../io")
DIR+=("../../ext")
DIR+=("../../sound")
DIR+=("../")
DIR+=("../ext")
DIR+=("../ext/c86ctl")
DIR+=("../ext/scci")

DIR+=(".")
DIR+=("./misc")
DIR+=("../../vram")
DIR+=("../../z80c")
DIR+=("../../codecnv")

echo "----- codelist -----"

echo "dirs:"
for item in ${DIR[@]}; do
    echo "$item "
done

for item in ${DIR[@]}; do
    echo "-- $item --"
    pushd $item > /dev/null
    ls -1 *.c
    ls -1 *.cpp
    popd > /dev/null
done