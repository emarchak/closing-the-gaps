/**
 * @file closing_the_gaps.scroll.js
 * Custom scrolling functionality to help keyboard navigation between anchor links.
 *
 */
(function ($, Drupal) {

  /**
   * Custom scrolling functionality.
   * This is not in a Drupal behavior, but an event handler instead to allow for any link to utilize this.
   */
  $(document).on('click', 'a[href^=#]', function () {
    var target = $(this).attr('href');
    // Ignore anchors linking to themselves.
    if (target === '#') {
      return;
    }

    // Ignore anchors linking to invisible elements.
    var $target = $(target);
    if ($target.length === 0) {
      return;
    }

    // Give focus to the current element.
    $(this).focus();

    // If we find the element, scroll. If not, return usual behaviour.
    var targetPosition = $target.offset();
    if (targetPosition.top) {
      $('html, body')
        .animate({scrollTop: targetPosition.top}, 600)
        .promise()
        .then(function () {
          $target.focus();
        });
    }
  });

})(jQuery, Drupal);
