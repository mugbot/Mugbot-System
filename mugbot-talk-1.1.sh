#!/bin/bash

HTSVOICE=/usr/share/hts-voice/nitech-jp-atr503-m001/nitech_jp_atr503_m001.htsvoice
#HTSVOICE=/usr/share/hts-voice/mei/mei_happy.htsvoice
DICDIRE=/var/lib/mecab/dic/open-jtalk/naist-jdic/
VOICEDATA=/tmp/voice.wav
echo "$1" | open_jtalk \
-x $DICDIRE 
-m $HTSVOICE \
-ow $VOICEDATA \
-s 17000 \
-p 100 \
-a 0.03 \
-b 0.0 \
-r 1.0 \
-fm 0.0 \
-u 0.0 \
-jm 1.0 \
-jf 1.0 \
-z 0.0 \

aplay -q $VOICEDATA
rm -f $VOICEDATA
