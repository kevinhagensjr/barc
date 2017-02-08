//
//  archive_stream.h
//  barc
//
//  Created by Charley Robinson on 1/26/17.
//  Copyright © 2017 TokBox, Inc. All rights reserved.
//

#ifndef archive_stream_h
#define archive_stream_h

#include <stdio.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

struct archive_stream_t;

int archive_stream_open(struct archive_stream_t** stream_out,
                        const char *filename,
                        int64_t start_offset, int64_t stop_offset,
                        const char* stream_name,
                        const char* stream_class);
int archive_stream_free(struct archive_stream_t* stream);

int archive_stream_peek_video(struct archive_stream_t* stream,
                              AVFrame** frame,
                              int64_t* offset_pts);

int archive_stream_pop_video(struct archive_stream_t* stream,
                             AVFrame** frame,
                             int64_t* offset_pts);

int archive_stream_pop_audio_samples(struct archive_stream_t* stream,
                                     int num_samples,
                                     enum AVSampleFormat format,
                                     int sample_rate,
                                     int16_t** samples_out);

int archive_stream_is_active_at_time(struct archive_stream_t* stream,
                                     int64_t global_time);

int* archive_stream_offset_x(struct archive_stream_t* stream);
int* archive_stream_offset_y(struct archive_stream_t* stream);
int* archive_stream_render_width(struct archive_stream_t* stream);
int* archive_stream_render_height(struct archive_stream_t* stream);
int64_t archive_stream_get_stop_offset(struct archive_stream_t* stream);
int64_t archive_stream_get_start_offset(struct archive_stream_t* stream);
const char* archive_stream_get_name(struct archive_stream_t* stream);
const char* archive_stream_get_class(struct archive_stream_t* stream);

#endif /* archive_stream_h */
