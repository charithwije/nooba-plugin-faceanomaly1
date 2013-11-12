#!bin/bash

git clone https://github.com/Asitha/nooba-plugin-template.git

plugin_name="$1"

TEMPLATE="TEMPLATE"
template="template"
Template="Template"

PLUGIN_NAME="${plugin_name^^}"
plugin_name="${plugin_name,,}"
Plugin_name="${plugin_name^}"

mv ./nooba-plugin-template $(echo "nooba-plugin-template" | sed "s/$template/$plugin_name/g") > /dev/null 2>&1

cd ./$(echo "nooba-plugin-template" | sed "s/$template/$plugin_name/g")

#changing directories
for i in 1 2 3; do
	for f in $(find -type d -not -path "*/.git*"); do

  		mv $f $(echo "$f" | sed "s/$TEMPLATE/$PLUGIN_NAME/g") > /dev/null 2>&1
  		mv $f $(echo $f | sed "s/$template/$plugin_name/g") > /dev/null 2>&1
  		mv $f $(echo $f | sed "s/$Template/$Plugin_name/g") > /dev/null 2>&1

	done
done

#changing filenames
for i in 1 2 3; do
	for f in $(find -type f -not -path "*/.git*"); do

  		mv $f $(echo $f | sed "s/$TEMPLATE/$PLUGIN_NAME/g") > /dev/null 2>&1
  		mv $f $(echo $f | sed "s/$template/$plugin_name/g") > /dev/null 2>&1
  		mv $f $(echo $f | sed "s/$Template/$Plugin_name/g")> /dev/null 2>&1
	done
done

#changing file content
for i in 1 2 3; do
	for f in $(find -type f -not -path "*/.git*"); do

  		sed -i "s/$TEMPLATE/$PLUGIN_NAME/g" $f > /dev/null 2>&1
  		sed -i "s/$template/$plugin_name/g" $f > /dev/null 2>&1
  		sed -i "s/$Template/$Plugin_name/g" $f > /dev/null 2>&1
	done
done

#restoring TEMPLATE keyword at the template of the project library

sed -i "s/$PLUGIN_NAME = lib/$TEMPLATE = lib/g" $(echo "./TemplatePlugin/TemplatePlugin.pro" | sed "s/$Template/$Plugin_name/g") > /dev/null 2>&1

#changing TARGET name
sed -i "s/TARGET = TestPlugin/TARGET = ${Plugin_name}Plugin/g" $(echo "./TemplatePlugin/TemplatePlugin.pro" | sed "s/$Template/$Plugin_name/g") > /dev/null 2>&1


sudo chown $USER -R ./*
