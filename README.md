# IGScraperKit

Create dynamic web scraper in Objective-C or Ruby.

## Usage

Create a scraper:

```objective-c
#import "IGScraperKit.h"
IGScraper* scraper = [IGScraper scraperWithBlock:^id(IGXMLNode* node, NSString* url) {
                return [[[node queryWithXPath:@"//p"] firstObject] text];
            }];
```

Then scrape HTML with scraper:

```objective-c
[scraper scrape:@"<html><p>Hello World</p></html>" url:nil];
// => @"Hello World"
```

If you want something more dynamic, you can define a Recipe in Ruby:

```ruby
class GoogleRecipe < ScraperKit::Recipe
  title "Google Search"

  on %r{https://www\.google\.com/search\?q=.+} do |doc, url|
    doc.xpath('//h3/a').collect {|node| node.text }
  end
end
```

Then load the recipe into IGRecipeRegistry and parse the page:
```objective-c
#import "IGScraperKit.h"

// load the recipe
NSString* path = [[NSBundle mainBundle] pathForResource:@"google" ofType:@"rb"];
NSString* recipe = [[NSString alloc] initWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
IGRecipeRegistry* registry = [[IGRecipeRegistry alloc] init];
[registry loadRecipe:Recipe(@"walmart")];

NSArray* result = [registry scrapeWithHTML:html url:@"https://www.google.com/search?q=doughnuts"];
// => <__NSArrayM 0xed85590>(
// Doughnut - Wikipedia, the free encyclopedia,
// Home - Krispy Kreme Doughnuts and Coffee,
// Voodoo Doughnut - The Magic is in the Hole!!!,
//【超人氣甜甜圈】Krispy Kreme Doughnuts 、台北店 ... - Yam天空部落,
// Doughnut Recipes - Allrecipes.com,
// Doughnut Plant,
// Revolution Doughnuts,
// Sidecar Doughnuts & Coffee,
// Top Pot Hand-Forged Doughnuts,
// Lucky's Doughnuts
// )

```

To use this, you will need to include JavaScriptCore framework (iOS 7, OS X 10.9) and define IGSCRAPERKIT_ENABLE_SCRIPTING before import `IGScraperKit.h`.

## Installation

To install IGScraperKit throught [CocoaPods](http://cocoapods.org/), add following lines to your Podfile:

```ruby
pod "IGScraperKit", :podspec => 'https://raw.github.com/siuying/IGScraperKit/master/IGScraperKit.podspec'
```

Or with Ruby supports:

```ruby
pod "IGScraperKit/Scripting", :podspec => 'https://raw.github.com/siuying/IGScraperKit/master/IGScraperKit.podspec'
```

## Dependencies

- IGScraperKit use IGHTMLQuery for HTML processing.
- IGScraperKit optionally use JavaScriptCore in iOS 7 for JavaScript support.
- Use phantomjs to run opal tests.

## Development

1. Install gems: In the project folder, run the command: ``bundle install``
2. Install cocoapods: Run the command: ``pod install``

## License

MIT License. Check LICENSE.txt.