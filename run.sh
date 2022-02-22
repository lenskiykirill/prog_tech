#!/bin/bash

INPUT_FOLDER="./folder"
EXTENSION="cpp"
BACKUP_FOLDER="./backup"
BACKUP_ARCHIVE_NAME="./backup.tar.gz"

LOGFILE="./.run.log"

while [[ $# -gt 0 ]]; do
      case $1 in
            --input_folder)
                  INPUT_FOLDER=$2;
                  shift;
                  shift;
                  ;;

            --extension)
                  EXTENSION=$2;
                  shift;
                  shift;
                  ;;

            --backup_folder)
                  BACKUP_FOLDER=$2;
                  shift;
                  shift;
                  ;;

            --backup_archive_name)
                  BACKUP_ARCHIVE_NAME=$2;
                  shift;
                  shift;
                  ;;
            *)
                  shift;
                  ;;
      esac;
done;

if [[ ! -d "$BACKUP_FOLDER" ]]; then
      mkdir -p "$BACKUP_FOLDER";
      echo "CREATED BACKUP FOLDER: $BACKUP_FOLDER" > $LOGFILE;
fi;

for FILE in $(find $INPUT_FOLDER -name "*.$EXTENSION"); do

      FILENAME=$(echo $FILE | rev | cut -d"/" -f1 | rev | cut -d"." -f1);

      if [[ -f "$BACKUP_FOLDER/$FILENAME.$EXTENSION" ]]; then
            SAVE_NUM=1
            while [[ -f "$BACKUP_FOLDER/$FILENAME($SAVE_NUM).$EXTENSION" ]]; do
                  (( SAVE_NUM+=1 ));
            done;

            cp "$FILE" "$BACKUP_FOLDER/$FILENAME($SAVE_NUM).$EXTENSION";
      else
            cp "$FILE" "$BACKUP_FOLDER/$FILENAME.$EXTENSION";
      fi;
done;

tar -czf "$BACKUP_ARCHIVE_NAME" "$BACKUP_FOLDER"
