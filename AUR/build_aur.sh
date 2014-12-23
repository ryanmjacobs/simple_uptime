#!/bin/bash

pkgname=simple_uptime
version=1.4

echo "Create source tarball..."
tar zvcf "$pkgname-$version.tar.gz" --transform="s/src/$pkgname-$version/g" ../src/

echo -e "\nGenerate new md5sum... "
sum="$(makepkg -g 2>/dev/null)"
sed -i "s/md5sum.*/$sum/g" PKGBUILD

echo -e "\nBuild AUR package..."
mkaurball -f

echo -e "\nClean up..."
rm -v *tar.gz
