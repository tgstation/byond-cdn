# Import the shit
FROM byond

# Set the shit
WORKDIR /byond-cdn

# Copy the shit
ADD . /byond-cdn

# Update the shit
RUN apt-get update -y && apt-get upgrade -y


ONBUILD ADD skin.dmf /byond-cdn
ONBUILD ADD resources.rsc /byond-cdn
ONBUILD RUN ./rscfilelist < resources.rsc > files.dm
ONBUILD RUN DreamMaker byond-cdn.dme
