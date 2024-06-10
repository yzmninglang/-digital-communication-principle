set data=%date:~3,10%
set currentDate=%data:~0,4%-%data:~5,2%-%data:~8,2%-%time:~1,1%-%time:~3,2%-%time:~6,2%.zip

git init
git add .
git commit -m "Init Project"
git archive -o %currentDate% master
