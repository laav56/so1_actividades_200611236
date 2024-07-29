#!/bin/bash

GITHUB_USER="laav56"

API_URL="https://api.github.com/users/${GITHUB_USER}"
RESPONSE=$(curl -s "$API_URL")

ID=$(echo "$RESPONSE" | jq -r '.id')
CREATED_AT=$(echo "$RESPONSE" | jq -r '.created_at')

MESSAGE="Hola ${GITHUB_USER}. User ID: ${ID}. Cuenta fue creada el ${CREATED_AT}"

DATE=$(date +"%d-%m-%Y")
LOG_DIR="/tmp/${DATE}"
LOG_FILE="${LOG_DIR}/saludos.log"

mkdir -p "$LOG_DIR"
echo "$MESSAGE" > "$LOG_FILE"

