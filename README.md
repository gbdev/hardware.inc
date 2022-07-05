# `hardware.inc`
### Gameboy Hardware definitions
`hardware.inc` has been the standard include file containing Game Boy hardware definitions for use in [RGBDS](https://rgbds.gbdev.io) projects for over 20 years.

The file was originally created by Jeff Frohwein in 1997, who still hosts [his latest version (2.3)](http://www.devrs.com/gb/files/hardware.zip) on his great [Dev'rs](http://devrs.com) website.

Although Jeff tried to version control the file with a rudimentary change log at the top of the file, people have added small changes throughout the years, often without bumping the version number.

This repo has become the new official reference for `hardware.inc`, using [@AntonioND](http://github.com/AntonioND)'s fork as the baseline.

## Contributing

This repository's `master` branch should be considered production;
Each commit represents a new release, requiring the embedded version number to be bumped (and an entry to be added to the changelog at the beginning of the file).

We follow [semantic versioning](https://semver.org);
Breaking changes (such as those in [72ec03f](https://github.com/gbdev/hardware.inc/commit/72ec03f835e72be83a1ef189a4a9eac0fbdf39e2)) increase the major version, backwards-compatible changes (typically additions) only increase the minor version, and bugfixes only increase the patch level.

Changes to the comments should be considered a bugfix.

## Contributors

* Jones (created the original `hardware.inc`, now lost)
* Carsten Sørensen (whose ideas Jeff based his file on)
* Jeff Frohwein
* AntonioND
* BlitterObjectBob, tobiasvl, ISSOtm, avivace, Eievui, QuinnPainter, rondnelson99, daid, Hacktix, sukus21, alvaro-cuesta, basxto
* Probably lots of other people who have added to the file throughout the years
