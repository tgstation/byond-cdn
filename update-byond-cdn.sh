#!/bin/bash

cd tgstation/
rm -f tgstation.rsc

git fetch origin
git reset --hard origin/master
DreamMaker tgstation.dme
cp -f tgstation.rsc ../byond-cdn-bagil/resources.rsc
cp -f interface/skin.dmf ../byond-cdn-bagil/skin.dmf

cp -f tgstation.rsc ../byond-cdn-sybil/resources.rsc
cp -f interface/skin.dmf ../byond-cdn-sybil/skin.dmf
cd ..

docker build -t byond-cdn byond-cdn/
docker build -t byond-cdn:sybil byond-cdn-sybil
docker build -t byond-cdn:bagil byond-cdn-bagil

docker tag byond-cdn:latest mrstonedone/byond-cdn:latest
docker tag byond-cdn:sybil mrstonedone/byond-cdn:sybil
docker tag byond-cdn:bagil mrstonedone/byond-cdn:bagil

docker push mrstonedone/byond-cdn

docker service update --image mrstonedone/byond-cdn:sybil byond-cdn-sybil
docker service update --image mrstonedone/byond-cdn:bagil byond-cdn-bagil