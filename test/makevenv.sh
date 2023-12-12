#!/bin/bash
python3 -m venv --clear --copies ./venv
source ./venv/bin/activate
./venv/bin/python3 -m pip install -r ./requirements.txt
