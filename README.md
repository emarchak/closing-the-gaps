## Closing the Gaps

### Prioritizing Accessibility in Custom Themes with Drupal 8

[@emarchak](http://twitter.com/emarchak) / [@myplanetHQ](http://twitter.com/myplanetHQ)


### What am I going to cover?

1. Why I'm here
2. A11y & Drupal 8
3. How to identify a11y gaps
4. How to resolve a11y gaps
5. Further resources

### Why I'm here

#### A Case Study

## AMI

> Myplanet had a lot of empathy for what we were trying to do. They felt and understood the mission we had for the site.

Virginia Vuleta  
_Director, Digital Strategy, Accessible Media Inc_

- User Experience Testing
- Design Audits
- A11y Audits by [David MacDonald](http://www.davidmacd.com/)
- Headless components using React.js

### A11y & D8


> The power of the Web is  in its universality.

[Tim Berners-Lee](http://www.w3.org/standards/webdesign/accessibility)

#### Types of barriers

- Physical, motor or mobile
- Visual
- Auditory
- Learning
- Speech or language
- Mental, intellectual or developmental

#### Types of solutions

- Keyboard, mouse & touch navigation
- Screen readers compatibility & descriptive video
- Captioning
- Legible design & information architecture
- Translatable content
- Trigger warnings for content

[The W3C Web Content Accessibility 2.0 Guidelines](http://www.w3.org/TR/WCAG20/) (WCAG 2.0)

#### WCAG 2.0 Levels

1. **Level A** - Essential
2. **Level AA** - Preferred
3. **Level AAA** - Optional

#### WCAG 2.0 Levels

1. **Level A** - Essential
2. **Level AA** - Preferred
3. **Level AAA** - Optional

#### Guidelines

- [Accessibility for Ontarians with Disabilities Act (AODA)](http://www.aoda.ca/) (Canada)
- [Government-wide Section 508 Accessibility Program](https://www.section508.gov/) (US)
- [European Union Accessibility Requirements](http://www.ssbbartgroup.com/laws-standards/european-union-accessibility-requirements/) (EU)

### A11y & D8

[#D8AX - Drupal 8 Accessibility eXperience](https://www.drupal.org/about/features/accessibility)

#### A11y in Drupal 8

- [WAI-ARIA](http://openconcept.ca/blog/mike/drupal-8%E2%80%99s-accessibility-advantage-wai-aria), [HTML5 & Improved Semantics](http://openconcept.ca/blog/mike/drupal-8%E2%80%99s-accessibility-advantage-html5-improved-semantics)
- [Content authoring](http://openconcept.ca/blog/mike/drupal-8%E2%80%99s-accessibility-advantage-alt-tags-defaults) & [ATAG Compliance](http://openconcept.ca/blog/mike/drupal-8%E2%80%99s-accessibility-advantage-atag-compliance)
- [Tab Control](https://www.drupal.org/node/1973218)[](https://www.drupal.org/node/1973218)
- [](https://www.drupal.org/node/1973218)[Aural Alerts](https://www.drupal.org/node/1973218)
- [Devel Accessibility](https://www.drupal.org/project/devel_a11y) module

[How Drupal 8 Makes Your Website More Easily Accessible](https://docs.google.com/presentation/d/19O3png9GsAam431zRd80EY3vDKMbXAnc4c0s2edpLa0/edit#slide=id.p6)

### We didn't want 

technically accessible, we wanted 

beautifully accessible

### How to identify a11y gaps

#### Visual Testing

- Plan heading structure early
- Prioritize function over form
- Allow indicators

#### Automated Functional testing

- [WAVE toolbar by WebAIM](http://wave.webaim.org/report#/http://events.drupal.org/dublin2016)
- [Tenon.io](https://tenon.io/index.php)

#### Manual Functional testing

- VoiceOver for macOS/iOS
- TalkBack for Android
- [NVDA](http://www.nvaccess.org/) for Windows
- [JAWS](http://www.freedomscientific.com/Products/Blindness/JAWS) for Windows

#### User Experience testing

- Pairs of researchers meet with individual users
- Examine behaviours & attitudes relevant to the workflow

### How to resolve a11y gaps

#### Functional solutions

##### Landmark Labels  

[Add descriptive aria labels to page landmarks.](https://github.com/emarchak/closing-the-gaps/commit/a7ce0ace5d36789c541f4cb396414f1b2b824f4d)

````
<main role="main" aria-label="{{ 'Content'|t }}">
````

##### Pagination  

[Improve legibility of pager for screen readers.](https://github.com/emarchak/closing-the-gaps/commit/a6f2ed3d1580de9a95cf5a8d844e3b67e1563ae6)

````
<li class="pager__item pager__item--next">
  <a class="button" href="{{ items.next.href }}" rel="next"{{ items.next.attributes|without('href', 'title', 'rel') }}>
    <span class="visually-hidden">{{ 'Next page'|t }}</span>
    <span aria-hidden="true">{{ items.next.text|default('Next ›'|t) }}</span>
  </a>
</li>
````

##### Form Errors  

Enable inline form errors, & [remove HTML5 required attribute.](https://github.com/emarchak/closing-the-gaps/commit/0cc1c6102675b0623612a3e8dc2439c0343eac4c)

````
if (isset($variables['attributes']['required'])) {
  unset($variables['attributes']['required']);
}
````

##### <Picture> element  

[Add Alternative text to picture elements.](https://github.com/emarchak/closing-the-gaps/commit/c515a3aa6e9b26e607d718d87dc11f95423a193a)

````
{% if img_element['#attributes'].url and alt %}
  <p class="visually-hidden">{{ alt }}</p>
{% endif %}
````

##### Skip to Main Content  

[Add js to help handle custom scrolling.](https://github.com/emarchak/closing-the-gaps/commit/00517f0e2dce5400c7d588886e11dc17d2c0ea3c)

````
$('html, body')
.animate({scrollTop: targetPosition.top}, 600)
.promise()
.then(function () {
  $target.focus();
});
````

##### Relate block titles & labels  

[Use aria labelled by on blocks to help with association.](https://github.com/emarchak/closing-the-gaps/commit/84d469397f8e3cc14baa038d9669f302ad947fd7)

````
<a
  id="{{ cta_id }}"
  class="btn btn-default"
  href="{{ content.field_call_to_action[0]['#url'] }}"
  aria-labelledby="{{ cta_id }} {{ heading_id }}">

````

#### Experiential solutions

##### Visual Design Best Practices

- Check early, check often
- [Sketch Color Contrast Analyser](https://github.com/getflourish/Sketch-Color-Contrast-Analyser)
- [WebAIM Accessibility Checklist](http://webaim.org/blog/accessibility-for-designers/)

##### UX Testing Best Practices

- Mixing remote and in-person testing
- Bring-your-own-device
- Emphasis on depth over breadth

### Further Resources

- Links contained in slide deck.
- [Future directions Drupal for accessibility](https://events.drupal.org/dublin2016/sessions/future-directions-drupal-accessibility) 09/29/2016 - 10:45
- [Empathy and future web accessibility](https://events.drupal.org/dublin2016/sessions/empathy-and-future-web-accessibility) 09/28/2016 - 12:00

## Thank you

[@emarchak](http://twitter.com/emarchak) / [@myplanetHQ](http://twitter.com/myplanetHQ)