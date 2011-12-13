$(document).ready(function() {
	// Stuff to do as soon as the DOM is ready;

		$('#next').click(function(e){
			var current=$('.current');
			var next=current.next('.slide');
			current.addClass('hidden').hide();
			next.removeClass('hidden').addClass('current').show();

		});
		
		$('#previous').click(function(e){
			var current=$('.current');
			var prev=current.prev('.slide');
			current.addClass('hidden').hide();
			prev.removeClass('hidden').addClass('current').show();
		});
});

