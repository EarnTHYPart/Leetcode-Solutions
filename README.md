# LeetCode Solutions

This repository stores accepted LeetCode solutions and keeps them in sync automatically using GitHub Actions.

## Automation Overview

This repository uses two workflows:

- Incremental sync: [.github/workflows/leetcode-sync.yml](.github/workflows/leetcode-sync.yml)
- One-time bulk sync: [.github/workflows/leetcode-bulk-sync.yml](.github/workflows/leetcode-bulk-sync.yml)

Both workflows:
- Authenticate to LeetCode using repository secrets.
- Write solution files into [solutions](solutions).
- Commit and push changes back to this repository.

## Workflow Details

### 1) Incremental Sync

File: [.github/workflows/leetcode-sync.yml](.github/workflows/leetcode-sync.yml)

What it does:
- Runs weekly and can also be triggered manually.
- Pulls recent accepted submissions only.
- Good for ongoing day-to-day automation.

Schedule:
- Every Sunday at 04:00 UTC
- Cron: `0 4 * * 0`

### 2) Bulk Sync (One-Time)

File: [.github/workflows/leetcode-bulk-sync.yml](.github/workflows/leetcode-bulk-sync.yml)

What it does:
- Runs manually only (`workflow_dispatch`).
- Iterates through all submissions pages and collects unique accepted problems.
- Useful for initial backfill of older accepted solutions.
- Usually run once, then keep using incremental sync.

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
2. Select either:
	- LeetCode Sync (incremental)
	- LeetCode Bulk Sync (one-time)
3. Click Run workflow.
4. Choose the `main` branch and run.

## Output Structure

Synced solutions are written to:
- [solutions](solutions)

Each file name is based on the problem slug and language extension, for example:
- `two-sum.cpp`
- `binary-gap.cpp`

## Notes

- If there are no new accepted submissions, the workflow exits without creating a commit.
- If secrets expire, update them in repository settings and run the workflow again.
- After your first complete backfill, prefer the incremental workflow for regular sync.
