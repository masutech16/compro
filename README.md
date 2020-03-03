# Competitive programming contest library and workspace settings
## Library
(Preparing...)

## How to use
### Create contest folder
```
mkdir workspace # only at the first.
cd workspace
acc new ${contest_name}
```

### Test sample case
```
# in /workspace
./test.sh ${problem_name}
```

### Submit your code
```
# in /workspace
./submit.sh ${problem_name}
```

### dependencies
This workspace uses
* [online-judge-tool](https://github.com/kmyk/online-judge-verify-helper)
* [online-judge-verify-helper](https://github.com/kmyk/online-judge-verify-helper)
  * for scripts bundle.
* [atcoder-cli](https://github.com/Tatamo/atcoder-cli)
