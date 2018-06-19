# base shit
FROM debian-i386

WORKDIR /byond

# Install any needed packages
ARG BYOND_MAJOR=512
ARG BYOND_MINOR=1427

RUN apt-get update && apt-get install -y curl unzip make \
        && curl "http://www.byond.com/download/build/${BYOND_MAJOR}/${BYOND_MAJOR}.${BYOND_MINOR}_byond_linux.zip" -o byond.zip \
        && unzip byond.zip \
        && cd byond \
        && sed -i 's|install:|&\n\tmkdir -p $(MAN_DIR)/man6|' Makefile \
        && make install \
        && chmod 644 /usr/local/byond/man/man6/* \
        && apt-get purge -y --auto-remove curl unzip make \
        && cd .. \
        && rm -rf byond byond.zip
