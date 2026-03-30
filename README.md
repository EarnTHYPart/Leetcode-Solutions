# LeetCode Solutions

This repository stores accepted LeetCode solutions and keeps them in sync automatically using GitHub Actions.

## Automation Overview

The workflow file is located at [.github/workflows/leetcode-sync.yml](.github/workflows/leetcode-sync.yml).

What it does:
- Runs on a weekly schedule and on manual trigger.
- Logs in to LeetCode using repository secrets.
- Fetches recent accepted submissions.
- Saves solution files into the [solutions](solutions) folder.
- Commits and pushes new or updated files back to this repository.

## Schedule

The workflow runs every Sunday at 04:00 UTC.

Cron expression:
- `0 4 * * 0`

## Required GitHub Secrets

Add these in:
Settings -> Secrets and variables -> Actions -> Repository secrets

- `LEETCODE_SESSION`
- `LEETCODE_CSRF_TOKEN`

Optional repository variable:
- `LEETCODE_SYNC_LIMIT` (default: 20)
- `LEETCODE_USERNAME` (default in workflow: EarnTHYPart)

## How To Run Manually

1. Open the Actions tab in GitHub.
2. Select the LeetCode Sync workflow.
3. Click Run workflow.
4. Choose the main branch and run.

## Output Structure

Synced solutions are written to:
- [solutions](solutions)

Each file name is based on the problem slug and language extension, for example:
- `two-sum.cpp`
- `binary-gap.cpp`

## Notes

- If there are no new accepted submissions, the workflow exits without creating a commit.
- If secrets expire, update them in repository settings and run the workflow again.
