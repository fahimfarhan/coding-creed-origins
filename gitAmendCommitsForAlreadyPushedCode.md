```
git rebase -i HEAD~n
```

This will show a list of last n commit messages like this:

```
pick e499d89 Delete CNAME
pick 0c39034 Better README
pick f7fde4a Change the commit message but push the same commit.
```

Change the `pick` with `reword`, then save and exit.
```
pick e499d89 Delete CNAME
reword 0c39034 Better README                // <-- I want to change this
pick f7fde4a Change the commit message but push the same commit.
```
Then all the commit messages with `reword` will show up one by one. Edit them. Finally force push them:
```
$ git push --force origin dev  # <-- or other branch , say master
```
 
Reference: [medium.com/@_oleksii_](https://medium.com/@_oleksii_/how-to-change-a-commit-message-in-git-after-push-32d1fbd6fc3b)
