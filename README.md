Собрать prophet можно так:

     docker pull guzelya/prophet
    docker run -it -u="ubuntu" -w="/home/ubuntu/" guzelya/prophet /bin/bash 
    
Получите id контейнера и его надо вписать в значение  docker_id

    dock_id="a0aad3811249"
    docker start $dock_id
    docker exec -it $dock_id bash

Чтобы обновить исходники 

    cd ~/Workspace/prophet/src git pull origin master

Чтобы собрать Prophet

     cd ~/Workspace/prophet make clean make CXXFLAGS="-Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-return-type"

Чтобы переучить модель 

    cd ~/Workspace/prophet/src/train
    python copyfiles.py

Чтобы проверить пример php-ecb9d80

    cd ~/Workspace/prophet/build/tests/php-case-ecb9d80/php-ecb9d80-workdir
    rm test.cache
    time /home/ubuntu/Workspace/prophet/src/prophet -r . -consider-all -feature-para /home/ubuntu/Workspace/prophet/crawler/para-php.out -first-n-loc 200 -stats -log=repair-log -summary-file=repair-summary -timeout=12
