#!bin/bash

git clone https://github.com/Asitha/nooba-plugin-faceanomaly1.git

plugin_name="$1"

FACEANOMALY1="FACEANOMALY1"
faceanomaly1="faceanomaly1"
Faceanomaly1="Faceanomaly1"

PLUGIN_NAME="${plugin_name^^}"
plugin_name="${plugin_name,,}"
Plugin_name="${plugin_name^}"

mv ./nooba-plugin-faceanomaly1 $(echo "nooba-plugin-faceanomaly1" | sed "s/$faceanomaly1/$plugin_name/g") > /dev/null 2>&1

cd ./$(echo "nooba-plugin-faceanomaly1" | sed "s/$faceanomaly1/$plugin_name/g")

#changing directories
for i in 1 2 3; do
	for f in $(find -type d -not -path "*/.git*"); do

  		mv $f $(echo "$f" | sed "s/$FACEANOMALY1/$PLUGIN_NAME/g") > /dev/null 2>&1
  		mv $f $(echo $f | sed "s/$faceanomaly1/$plugin_name/g") > /dev/null 2>&1
  		mv $f $(echo $f | sed "s/$Faceanomaly1/$Plugin_name/g") > /dev/null 2>&1

	done
done

#changing filenames
for i in 1 2 3; do
	for f in $(find -type f -not -path "*/.git*"); do

  		mv $f $(echo $f | sed "s/$FACEANOMALY1/$PLUGIN_NAME/g") > /dev/null 2>&1
  		mv $f $(echo $f | sed "s/$faceanomaly1/$plugin_name/g") > /dev/null 2>&1
  		mv $f $(echo $f | sed "s/$Faceanomaly1/$Plugin_name/g")> /dev/null 2>&1
	done
done

#changing file content
for i in 1 2 3; do
	for f in $(find -type f -not -path "*/.git*"); do

  		sed -i "s/$FACEANOMALY1/$PLUGIN_NAME/g" $f > /dev/null 2>&1
  		sed -i "s/$faceanomaly1/$plugin_name/g" $f > /dev/null 2>&1
  		sed -i "s/$Faceanomaly1/$Plugin_name/g" $f > /dev/null 2>&1
	done
done

#restoring FACEANOMALY1 keyword at the faceanomaly1 of the project library

sed -i "s/$PLUGIN_NAME = lib/$FACEANOMALY1 = lib/g" $(echo "./Faceanomaly1Plugin/Faceanomaly1Plugin.pro" | sed "s/$Faceanomaly1/$Plugin_name/g") > /dev/null 2>&1

#changing TARGET name
sed -i "s/TARGET = TestPlugin/TARGET = ${Plugin_name}Plugin/g" $(echo "./Faceanomaly1Plugin/Faceanomaly1Plugin.pro" | sed "s/$Faceanomaly1/$Plugin_name/g") > /dev/null 2>&1


sudo chown $USER -R ./*
