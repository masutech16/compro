# Competitive programming library and workspace settings
## Library
(Preparing...)

## How to use this workspace
### When participating AtCoder contest
#### Create contest folder
```
cd workspace
acc new ${contest_name}
```

#### Test sample case
```
# in /workspace
./test.sh ${problem_name}
```

#### Submit your code
```
# in /workspace
./submit.sh ${problem_name}
```

### Otherwise

#### Create a problem folder
```
# NOTICE: Folder_name should be different according to problems. If the same name is used, url suggestion of online-judge-tools is not worked.
cd workspace
./gen.sh ${url} ${folder_name}
```

At this time, watch.sh starts running and compiling automatically on save.

#### Test and submit your code
```
# Open other shell or press Ctrl+C to execute the following command.

# To test your code
cd {folder_name} && oj t

# To submit your code.
./submit.sh # Bundle and submit code.
```

### dependencies
This workspace uses following library.
* [online-judge-tool](https://github.com/kmyk/online-judge-verify-helper)
* [online-judge-verify-helper](https://github.com/kmyk/online-judge-verify-helper)
  * For scripts bundle.
* [atcoder-cli](https://github.com/Tatamo/atcoder-cli)
