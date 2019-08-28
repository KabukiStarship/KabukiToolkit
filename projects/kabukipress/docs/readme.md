# KabukiPress

## Docs

This folder contains the docs for KabukiPress. This file contains the Frequently Asked Questions.

### Documents

* [Contributing](./contributing.md) - A short guide for how to contribute to this project.
* [Roadmap](./roadmap.md) - The KabukiPress project roadmap.

### Frequently Asked Questions

1. What does KabukiPress do?
   * KabukiPress is an extendable set of tools for writing, editing, and publishing books, blogs, catalogs, and documents to various document formats and statically generated websites using IMUL and Markdown.
1. Why would I want to use KabukiPress?
   * For the same reasons you would want to use Jekyll and use Markdown in the first place. KabukiPress was initially designed for writing books in Markdown using a tree file structure with one section per file. This format was chosen because Markdown renders at the time were notoriously slow rendering while editing large markdown files, so splitting the files up alleviates that issue. The side effect of splitting the files up is that it's easier to edit books when you block out everything else and only focus on one section and one issue at a time. This concept soon became useful for creating blogs with, and KabukiPress was born.
1. What is the benefit of KabukiPress over Jekyll?
   * It's a LOT fastest because it's written in Modern Embedded-C++ using the Script2 unit test and IoT app framework. This means that you can start out with a free GitHub Pages site, and scale it right on up to the one of the highest performance web servers possible. Script2 provides a database technology similar to MongoDB so it can compete with the highest performance web apps.
1. Can I work with Kindle Create for Kindle Direct Publishing?
   * Yes. KabukiPress (will in the future) works with Kindle Create by interfacing through the MS Word document in your Kindle Create project folder. KabukiPress (in the future) will allow you to sync your changes one way, or sync changes between MS Word and KabukiPress.
1. How do I do collaborative editing with KabukiPress?
   * To collaborate on documents with KabukiPress it is recommended to use [Visual Studio Code](https://code.visualstudio.com/)'s Live Share feature. This integrates directly with the Git Revision Control System for industry-standard data backup.
1. How do I use KabukiPress?
   * The [Kabuki Toolkit Cookbook](https://github.com/kabuki-starship/kabuki_toolkit.cookbook/blob/master/README.md) is the official documentation.
