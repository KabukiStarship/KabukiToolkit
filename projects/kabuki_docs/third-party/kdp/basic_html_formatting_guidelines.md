# Basic HTML Formatting Guidelines

This help page is a basic introduction to modifying your title in HTML. Once you've converted your content and uploaded your book using Kindle Direct Publishing, you may want to make changes. If you have basic HTML knowledge, you can modify the converted HTML file to refine your formatting and layout. We recommend that you proceed only if you're familiar with using HTML tags.

KDP compresses your converted content into a .zip file which contains an HTML file of your text content, as well as any included images. You can download the .zip file, edit the HTML file, then re-zip and re-upload the content. Make sure all your content (including images) is in a single folder in the zip file, without any sub-folders.

## How to export HTML from KDP

1. Go to your Bookshelf
2. Under the KINDLE EBOOK ACTIONS menu, click on the ellipsis button ("...") next to the book you want to edit
3. Select "Edit eBook Content"
4. Scroll down to the "Kindle eBook Preview" section and click Preview on your computer
5. Download and open your converted book file in HTML
6. Open the .zip file and save your HTML file
7. Open and edit the HTML file with the HTML editor of your choice (e.g., Notepad).

## Text guidelines

### Normal Text

The "normal" text in a Kindle book must be all defaults. We encourage content creators to use creative styles for headings, special paragraphs, footnotes, tables of contents and so on but not "normal" text. The reason is that any styling on "normal" text in the HTML would override the user's preferred default reading settings. Users tend to report such behavior as a poor experience.

Here are the most important points:

* "Normal" text must not have a forced alignment (left aligned or justified). "Normal" text must not have a forced line-height attribute, either.
* "Normal" text must use the default font family. The font face="…" tag is ignored on the Kindle platform but even so, make sure it is not used on "normal" text. The same applies to the CSSfont-family style.
* "Normal" text must use the default font size. The font size="…" tag or its equivalent in CSS should not be used in "normal" text. "Normal" text should not be bold or italicized. Selected parts can of course use such styling. This guideline only prohibits book that would be entirely bold, for example.
* "Normal" text should not have an imposed font color or background color.

### Page breaks

Blank lines of text should not be inserted to create empty pages. Use the page break tag 'mbp:pagebreak/'. This is especially true for documents generated from Microsoft Word; you should use the "Page Break" feature of Word.
Line breaks and spacing

Create line breaks using the <br> (break) tag, not the <p> (paragraph) tag. Body text should not use the “line-height” attribute. Using fixed values like this can override the user’s preferred default reading settings.

### Paragraph formatting

The First line of every paragraph is automatically indented. This behavior can be changed using the text-indent style on the 'p' tag. For example:

* p style="text-indent:0" - no indentation of the first line 
* p style="text-indent:10%" - positive indent, 10% of the width of the page
* p style="text-indent:5em" - positive indent, 5 em 
* p style="text-indent:-10pt" - negative indent, 10 pt 
* p style="text-indent:-10" - negative indent, 10 pixels ; The space before each paragraph can be changed using the "margin-top" style on tag p.
 
 Background color cannot be set on text. Also, Borders cannot be added to paragraphs.

### Raised initials

To make the first letter in a paragraph larger than the text that follows, use the font tag with the "size" attribute and specify a larger font size for the first letter. 
For example: Once upon a time...

### Text positioning and margins

At this time, Amazon KDP doesn't support margins set inside CSS/HTML (such as topmargin, leftmargin etc. set in px values). You can use the CSS margin attribute for positive values and percentage values (as opposed to hard-coded values), but depending on your text format, this might not translate properly. You can set only the left, top, and bottom margins this way, never the right margin.

**Note:** Avoid using negative values for positioning text and margins. Positioning with negative values without adding padding for compensation can cause content to display with the edge cut off. For example, if you want to use text-indent: -2em you also need to apply padding-left: 2em.

### Page numbers

Kindle eBooks are reflowable and can be viewed with different font sizes, so page numbers do not apply. There should not be any reference to page numbers in the book. The cross references should not have page numbers, nor should there be any plain text index with page numbers.

### Font size

If your font size is inconsistent or doesn't change when the settings are adjusted, the problem may be caused by the fixed value "font-size." To enable rendering across various screen sizes and resolutions, set the body text font using the "font-family" attribute. Body text must use the default font size (1em) and line height. Body text should not use the "font-size" attribute.

### Font color

Body text should not have an imposed font color throughout the book. If you prefer to use imposed font color in some sections of your book, do not use too light or too dark a color. Light colors will not display with enough contrast on devices set to white backgrounds or on E-reader devices. Dark colors will not display well on devices set to black backgrounds.

Does your book display blank pages on Kindle tablets used in night mode? This problem may be caused by forced colors or background colors. If the body text color or background color is forced to black & white, the text may not be visible in night mode. To fix this, remove color attributes like “font-color” and “background-color.”

To determine whether your background color is set, please save the DOC file as HTML (Web Page, Filtered) and then right click on the HTML file and move the mouse pointer to "Open with > Notepad." You can search the file using the "CTRL + F" keys using the words "Color" or "Background" to see if you have forced the color coding. You can remove this coding and save the file.
Cascading style sheets (CSS)
Cascading Style Sheets (CSS) must be contained in a dedicated CSS file, which is separate from your HTML content. Use a tag to link the CSS file to an HTML file. For example:

```HTML
 <head>
 <link rel="stylesheet" type="text/css" href="theme.css">
 <head>
 ```

** Note:** All HTML and CSS files must be compressed into a single .zip file before uploading.

## Image/table/table of contents guidelines

### Supported formats

The Kindle platform supports GIF, BMP, JPEG, non-transparent PNG, and Scalable Vector Graphics (SVG) images. 

When using images for schemas, charts, tables, maps, or anything that includes text, pay special attention to the legibility of the final image. Images are added to the source using standard HTML, for example, < img src="image name.gif" />. If you want the image to fit the reader's screen size, add height="100%" to your  tag, for example, < img src="image name.gif" height="100%" />.

See our Help page to learn more about formatting images.

### Automatic image conversions

The maximum size of a MOBI file is 650 MB. Once you upload your source file on KDP, KindleGen performs automatic image conversions to optimize the content for Kindle. Optimize your images to the highest quality possible within the file size limit before inputting your files into KindleGen.

### Color

Use color images whenever possible and relevant. The Kindle reading device has a black and white screen today but Kindle applications for other devices, such as iPhone or PC, take advantage of colors.

### Photographs

Photographs should use the JPEG format with a quality factor of 40 or higher. Photographs should be provided with the highest resolution available to you.

Photographs should not be too small. Please make sure your input photos are at least 600x800 pixels in size, unless you optimize them yourself according to the previous guideline. Photographs of less than 300x400 pixels are much too small and can be rejected.

If your photographs are in GIF format or are too small, simply converting them to JPEG or artificially increasing their size will not improve their quality. You should go back to the original source to create a JPEG image with sufficient resolution.

### Missing images

Images may be missing if they aren't correctly referenced in the ZIP folder. When you save your Word file as HTML (Web page, filtered), a separate HTML file and a separate folder containing all your images is created in the same location on your computer.

To "ZIP" the HTML content file and image folder together:

1. Select both the content file and the image folder by pressing the Ctrl key and clicking on both.
2. Once the files are selected, right-click on one of the highlighted files and select "Send to"
3. Select "Compressed(Zipped) folder"

After confirming your files are in this zipped folder, upload it to KDP, then verify that the images appear correctly in the previewer before publishing your book.

### Tables

We recommend using HTML layouts and instead of inserting tables as images. If the table is rendered using HTML tags, pagination is available and users can cursor throughthe cells in the table. For the best user experience, tables should not contain whole paragraphs of text or large pictures in a cell.

If a table is too large or contains too much text in its cells, consider reformatting it in a way that makes it easier to read. Single columns of HTML text provide the best reading experience for customers using a variety of font sizes. To learn more about formatting tables in HTML, see section 9.5 of the Kindle Publishing Guidelines.

### Tables of contents

We recommend the use of an HTML table of contents (TOC) for all books that would benefit from this navigation feature. Also, Amazon requires that all eBooks include a logical TOC. The logical TOC is important for a good reading experience because it allows a reader to navigate between chapters easily. Users expect to see an HTML TOC when paging through a book from the beginning, while the logical TOC is an additional way for users to navigate books. The inclusion of a logical TOC is especially important for books that are longer than 20 pages.

To learn how to create a logical or HTML TOC, see our Help page.

For detailed instructions, see section 5 of the Kindle Publishing Guidelines.

## How to re-upload your book

1. Copy your edited HTML file back into the .zip file you downloaded above. Make sure all the images and HTML files are in a single folder without any content in sub-folders. 
2. Go to your Bookshelf
3. Under the KINDLE EBOOK ACTIONS menu, click on the ellipsis button "..." next to the book you edited
4. Select "Edit eBook Content"
5. Scroll down to the "Manuscript" section
6. Click Upload eBook Manuscript
7. Scroll down to the bottom of the page and click Save and Continue