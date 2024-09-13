# ITDEL - CTF Challenge Environments

[![All Contributors](https://img.shields.io/badge/all_contributors-6-darkblue.svg?style=flat-square)](#contributors-)

ITDEL CTF is an annual national cyber security competition organized by ITDEL in Indonesia.

On 2024, ITDEL For the preliminary stage, the competition format follows the Jeopardy style, where teams compete in various categories of challenges.

## Table of Contents

- [Usage](## Usage)
- [Format Flag](## Format-Flag)
- [List of Challenges](## List-of-Challenges)

## Usage

The installation steps of docker and docker-compose for others operating system might be slightly different, please refer to the [docker documentation](https://docs.docker.com/) for details.

Every service will use different port. To setting port use <code> docker-composer.yml </code> on every challenge.

## Format Flag

1. The flags must be enclosed in `ITDEL{}`.
2. They can have numbers, alphabets, `_`s, `'`s, `!`s, `.`s, `+`s, `-`s, `@`s, `#`s, `$`s, `%`s, `:`s, `>`s.
3. They must be related to the challenge.
4. They must not be so simple that you can guess them.

Here's a regex for the flag format.

```bash
/^ITDEL{[\w_!@#?$%\.'"+:->]{5,50}}$/
```

Here's a sample flag.

```bash
ITDEL{hell0W_olrd_!5Simpl3#}
```

## List of Challenges

| No  | Category | Challenge Name | Author       | Connection           |
| --- | -------- | -------------- | ------------ | -------------------- |
| 1   | WEB      | BMICalc        | VascoZ       | http://HOSTNAME:7008 |
| 2   | WEB      | Art Of War     | VascoZ       | http://HOSTNAME:7009 |
| 3   | WEB      | Anywhere Door  | VascoZ       | http://HOSTNAME:7010 |
| 4   | REV      | Flagcheck      | .jagungrebus | -                    |
| 5   | REV      | Hadiah Gokil   | .jagungrebus | http://HOSTNAME:7021 |
| 6   | REV      | Forbidden Item | .jagungrebus | -                    |
| 7   | REV      | temenlama      | hanz0x17     | -                    |
| 8   | PWN      | hakc dis atm   | hanz0x17     | nc HOSTNAME 7015     |
| 9   | OSINT    | Git Osint      | hanz0x17     | -                    |
| 10   | CRY    | Base_QwErTyUiOpA      | wonping     | -                    |
| 11   | CRY    | JustSolveIT      | wonping     | nc HOSTNAME 7030                    |
| 12   | CRY    | Reuse      | wonping     | -                    |


