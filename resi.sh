#!/bin/bash

read -p "Masukkan nomor resi: " RESI
RESI_UP=$(echo "$RESI" | tr '[:lower:]' '[:upper:]')

if [[ $RESI_UP == JNE* || $RESI_UP == JP* ]]; then
  KURIR="jne"
elif [[ $RESI_UP == JX* || $RESI_UP == JT* ]]; then
  KURIR="jnt"
elif [[ $RESI_UP == SCP* || $RESI_UP == 002* ]]; then
  KURIR="sicepat"
elif [[ $RESI_UP == P* ]]; then
  KURIR="pos"
else
  read -p "Kurir tidak terdeteksi, isi manual: " KURIR
fi

case $KURIR in
  jne) URL="https://www.jne.co.id/tracking-package?awb=" ;;
  jnt) URL="https://www.jet.co.id/track?awb=" ;;
  sicepat) URL="https://www.sicepat.com/checkAwb/" ;;
  pos) URL="https://www.posindonesia.co.id/id/tracking/" ;;
  anteraja) URL="https://anteraja.id/tracking?awb=" ;;
  *) echo "Kurir tidak valid"; exit 1 ;;
esac

FULL="$URL$RESI"
echo "Tracking URL: $FULL"
